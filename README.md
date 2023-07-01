# cpp-go-node-comparision

A dead simple application written in `go`, `node` and `c++` presented on [JsCraftcamp2023](https://twitter.com/hashtag/jscc23?src=hashtag_click) to show case how the technologies behave and performance on a given condition.

The application expects 2 parameters, a `number` and a `string`, with the first parameter the program iterates calculting the factorial 
(then we can test recursion and call stack limits) of each number, saving it, firstly in memory and later to a file disc (second string param).

This is not intendend to be any sort of decisive argument, but just to bring more content into the discussion.

`c++` performance has certain variations based on which compiler you use and how you compile the program (which [optimizations](https://gcc.gnu.org/onlinedocs/gcc/Optimize-Options.html) are applied).

Also we can see the node applicability which in this case evidences that high performatic application may not be the right tool.

Feel free to get the source, compile it (c++ and go case) and may let a feedback :)
