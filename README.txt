Rebecca Hanessian
CS 4280 P1

Option 1

Compile using make and make clean

Submission: /accounts/classes/janikowc/submitProject/submit_cs4280_P1 SubmitFileOrDirectory

Invocation: P1 [file] where file is file.sp23 (the extension is implicit)

P1 // read from the keyboard until simulated EOF
P1 < somefile // same as above except redirecting from somefile instead of keyboard
P1 somefile  // read from somefile.sp23

Implement scanner for the provided lexical definitions
(String reader that uses spaces to separate tokens)
Implement a token as a triplet {tokenID, tokenInstance, line#}