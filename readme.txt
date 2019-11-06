Title { DES Door entry system }

Author { 
Cory Chenier chen0608@algonquinlive.com 040868909
Vicknesh Babu babu0016@algonquinlive.com 040875391
}
Contributions {
Cory Chenier: Wrote most of Des_inputs, including connection and 
message passing, conditional statments to check user input
and set the state machine in motion.
Wrote a portion of des_controller, including connection to display, 
channel create functions, and initial start to the state machine.
Wrote a portion of .h file, including states, initial concept for person 
object and function pointer declarations.
Provided general bug fixes to all files. 
Documentation
Debugging

Vicknesh: Wrote all of des_display. Wrote a portion of des_controller 
including all function pointers logic, including sending the message to the display.
Provided general bug fixes to all files. Wrote a portion of .h file. 
Including the final build of the person struct, all input and output messages.
Documentation. 
Testing

Status: currently, the program steps through the state machine with correct inputs, 
outputting an invalid state if the user enters one. Allows the user to exit at any time, 
ending all processes. 

Does it exit unexpectantly? Not with our testing.

Known issues: Writing a GRL on the left side or a GLL on the right side will set our
side back to 0. This will even happen if entered prematurally but it was our only 
solution at last minute. Entering an opposite input side in the same function: Example RO after LO
Will cause the display to output the first message in our outputs. Any other occurences of RO will
indeed output invalid state. User will be able to continue normally though.

Expected Grade: B+/A- I think we came up with a pretty elegant solution to eliminating many states,
adding ambiguity to which side you are on in the states, as well as having two arrays of inputs, using
the index of the state and which side the person is on to properly check user input.


