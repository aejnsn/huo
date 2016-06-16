# huo
Writing an interpreted language in C for fun.

##features
It has lispy syntax because it's easy to parse into a tree.
```lisp
(+ 3 (* 4 3))
```
Numbers are all doubles unless you divide them. Then they are all floats.
```lisp
(+ 3 3) ; 6

(+ 3 (/ 10 4)) ; 5.500000

(* 3 (/ 10 4)) ; 7.500000
```
Huo currently supports the following functions:
```c``lisp
basic math
+ - * /
```
print: print a value to the console
```lisp
(print (* 3 6)) ; prints 18 to the console
```
cat: concatenate strings
```lisp
(cat "hello " "world!") ; returns "hello world!"
```
booleans
```lisp
(= 3 2) ; returns false
(= 1 1) ; returns true
(= "Hey" "hey") ; returns true

(! 1 3) ; returns true
(! "Hey" (cat "He" "y")) ; returns false
```
let bindings
```lisp
(let x 5)
(print (+ x 3) ; prints 8
```
arrays
```lisp
(let x [1,2,3,4])
(print x) ; prints [1, 2, 3, 4]
(let y [[1,2], [3,4]]) ; nesting is fine
(let z [[3,4], [5,6]])
(print (+ y z)) ; adding nested arrays; prints [[4,6], [8,10]]

; use index to return a single array value
(index 2 [1, 2, 3]) ; -> 2

; push and length are straight-forward
(push 5 [1, 2, 3, 4]) ; -> [1, 2, 3, 4, 5]
(length [1, 2, 3]) ; -> 3

; use set to change a value at a specific index
; it takes index, item, and array as args
(set 0 10 [1,2,3,4]) ; -> [ 10, 2, 3, 4 ]

; map and each both take four arguments:
; first the array you want to iterate over
; the names for the current item and the index
; in the array, and then the function to call each iteration
(let x [1, 2, 3])
(let y 0)
(each x num idx (let y (+ y num)))
(print y) ; -> 6
(map x num idx (+ num idx))
(print x) ; -> [1, 3, 5]

; reduce is different, it takes the array to iterate over,
; the names of the accumulator and the current item, the function to
; call each iteration, and an optional initial value for the accumulator
(def avg x
    (/
        (reduce x acc cur (+ acc cur))
        (length x)
    )
)
(let x [1,2,3,4,13])
(print (reduce (push 4 [1,2,3]) acc cur (+ acc cur) 0)) ; -> 10
(print (avg x)) ; -> 4.600000
```
for loop
```lisp
; the for loop takes three arguments
; start number, end number, function to call each iteration
; start and end can be functions that return numbers
(let x [])
(for 0 10 
    (set (length x) 0 x)
)
(print x) ; -> [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
```
do block
```lisp
; because each, reduce, and for loop only take one function
; the do block is a function that takes n functions and executes them
; in order, returning the value from the last function inside it
(let x [1,2,3,4,5])
(each x item idx 
    (do 
        (let n (* item idx))
        (set idx n x)
    )
)
```

##compile
make   
make clean   

##run
create a huo file syntax:   
test.txt
```code
(print (+ 1 3 ( * 2 3 ) ( / 6 2 )))
```

run the file:
```shell
$ ./huo test.txt
```
