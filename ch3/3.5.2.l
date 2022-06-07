%{
%}

delim 	[ \t]
ws 			{delim}+
letter 	[a-zA-Z]
word   	{letter}+

%%
{ws} { printf(" "); }
{word} { printf("%s", yytext);}
%%