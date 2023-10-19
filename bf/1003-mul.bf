>, >, <<  // Read two numbers from stdin into cell 0 and cell 1 then move back to cell 0

++++++
[
 >---- ---- // Subtract 48 from each number to convert from ASCII to integer
 >---- ----
 <<-  // Move back to the first number
]

>
[           //multiply
 >[>+>+<<-]  // Move the first number to cell 2 and cell 3
 >[<+>-]    // Move cell 2 back to the first number
 <<-        // Move back to the first number and decrement it
]

>[-]>+> >+++++ +++++<  // Prepare cell 3 with 10 and cell 4 with 0
// Division loop (to separate the tens and units digits)
[
 - >- [>>>]+++++ +++++<<+  // Subtract 10 from the result and add 1
 [<<<]>>>>  // If the result is not zero move back to it
]

<-  // Move the remaining units digit to cell 5
<+++++ +++++>>>[-<<<->>>]<<< // Add 48 to cell 5 to convert it to ASCII

<+++++ + // Add 48 to cell 4 to convert it to ASCII
[
 >++++ ++++> // Add 48 to cell 4 to convert it to 
 [++++ ++++>]
 <[<]>- // Move back to cell 3
]

>>[.<<]<[<<]>>. // Print the tens and units digits
>>>>>>>>>>>>>>>>>>>>>>>++++++++++. // Move to a new cell and print a newline
