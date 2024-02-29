// Equation ->  a = b = c + d + e + f * g - h / d

// Precedence -> *,/  ->  +,-  ->  =

// Assosiativity ->  (* , /) = L -> R   
                 //  (+ , -) = L->R 
                //   ( = ) = R->L

// Using Stack to store the operators
// Using Array to store the Operands

// STACK
//      Check Precedence of Operator out and top
//              -> HIGH  =>  Push To stack
//              -> LOW   =>  POP operator | Add to Array
//              -> SAME  =>  Check ASSOSIATIVITY : 
//                                   -> Left to Right   =>  POP operator | Add to array
//                                   -> Right to Left   =>  PUSH To stack
//              -> End of expresion => POP and ADD to Array



// 
// In equation
//      ARRAY => a
//      STACK => 

//      ARRAY => a 
//      STACK => = 

//      ARRAY => a , b
//      STACK => = 

//      ARRAY => a , b
//      STACK => = , =

//      ARRAY => a , b , c
//      STACK => = , =

//      ARRAY => a , b , c
//      STACK => = , = , +

//      ARRAY => a , b , c , d
//      STACK => = , = , +

//      ARRAY => a , b , c , d , +
//      STACK => = , =

//      ARRAY => a , b , c , d , +
//      STACK => = , = , +

//      ARRAY => a , b , c , d , + , e
//      STACK => = , = , +

//      ARRAY => a , b , c , d , + , e , +
//      STACK => = , =

//      ARRAY => a , b , c , d , + , e , +
//      STACK => = , = , +

//      ARRAY => a , b , c , d , + , e , + , f
//      STACK => = , = , +

//      ARRAY => a , b , c , d , + , e , + , f
//      STACK => = , = , + , *

//      ARRAY => a , b , c , d , + , e , + , f , g
//      STACK => = , = , + , *

//      ARRAY => a , b , c , d , + , e , + , f , g , *
//      STACK => = , = , + 

//      ARRAY => a , b , c , d , + , e , + , f , g , * , +
//      STACK => = , = 

//      ARRAY => a , b , c , d , + , e , + , f , g , * , +
//      STACK => = , = , -

//      ARRAY => a , b , c , d , + , e , + , f , g , * , + , h
//      STACK => = , = , -

//      ARRAY => a , b , c , d , + , e , + , f , g , * , + , h
//      STACK => = , = , - , /

//      ARRAY => a , b , c , d , + , e , + , f , g , * , + , h , d
//      STACK => = , = , - , /

//      ARRAY => a , b , c , d , + , e , + , f , g , * , + , h , d, /
//      STACK => = , = , - 

//      ARRAY => a , b , c , d , + , e , + , f , g , * , + , h , d, / , -
//      STACK => = , =

//      ARRAY => a , b , c , d , + , e , + , f , g , * , + , h , d, / , - , =
//      STACK => = 

//      ARRAY => a , b , c , d , + , e , + , f , g , * , + , h , d, / , - , = , =
//      STACK => 


// VERIFICATION => a=5 , b=6 , c=7 , d=8 , e=9 , f=10 , g=11 , h=12

// New Stack => Operand Stack
// When ever you see an operand PUSH to Stack
// When you see an operator, POP 2 complete the operation with the operator | PUSH Val to Stack

// Example

// ANSWER STACK => a 
// ANSWER STACK => a , b
// ANSWER STACK => a , b , c 
// ANSWER STACK => a , b , c ,d
// ANSWER STACK => a , b , 15
// ANSWER STACK => a , b , 15 , e
// ANSWER STACK => a , b , 24
// ANSWER STACK => a , b , 24 , f
// ANSWER STACK => a , b , 24 , f , g
// ANSWER STACK => a , b , 24 , 110
// ANSWER STACK => a , b , 134
// ANSWER STACK => a , b , 134 , h
// ANSWER STACK => a , b , 134 , h , d
// ANSWER STACK => a , b , 134 , 1
// ANSWER STACK => a , b , 133
// ANSWER STACK => a ,133               |   b = 133
// ANSWER STACK =>                      |   b = 133   |  a = 133


