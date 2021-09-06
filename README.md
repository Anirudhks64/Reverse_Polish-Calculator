# Reverse_Polish-Calculator

In this project we have built a calculator which converts mathematical expressions into Reverse Polish notation. Reverse Polish Notation is a way of writing and evaluating mathematical expressions that is commonly used in industries such as engineering and finance. One of its biggest advantages is that there are no parentheses to alter precedence, and so calculation  flows from left to right without jumping around. It is often the case that software offering infix notation (where the operator is between the operands) will  first convert the infix expression to postfix (where operators follow their operands, as in RPN) prior to performing a calculation. For example, to write the expression  24 + 18  in RPN:  24 18 +. We use a stack to evaluate expressions. Each value in the expression (either a number or an operator) is considered a token. The algorithm looks like this: 
1. Start with an empty stack 
2. Read a token and create a node from it, marking it as either NUMBER or OPERATOR; 
  use malloc( ) to allocate space for the node 
3. If the node contains a number, push it onto the stack 
4. If the node contains an operator
    A. Pop two values 
    B. Apply the operator 
    C. Push the result (in a new node) to the stack When you've reached the end of the expression, there should be just one node on the stack, holding the        evaluation of the expression.
The project uses the Dijkstra's Shunting-Yard Algorithm to implement it for more than 2 numbers and operations. (https://en.wikipedia.org/wiki/Shunting-yard_algorithm)
