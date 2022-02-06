pragma solidity ^0.4.24;

contract HelloWorld {

    string saySomething;

    constructor() public  {
        saySomething = "Hello World!";
    }

    function saySomethingElse(string newSaying) public {
        saySomething = newSaying;
    }

}