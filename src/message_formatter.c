// This will take the unformatted messages and convert them into nice user readable ones.

// Based on the IRCv3 Spec

// Messages are seperated by CR-LF. Theoretically we will only receive one message at a time anyway but it's worth verifying.

// If the first charecter of a message is ':', this denotes there IS a prefix
// Otherwise there is no prefix.

// A standard message is in the following format [:]<prefix>:<message>CRLF  