grammar lexer_hidden_channel;

channels
{
    WSCHANNEL,
    MYHIDDEN
}

WS:[ \t]+ -> channel(MYHIDDEN);

ID: "id" -> channel(WSCHANNEL);