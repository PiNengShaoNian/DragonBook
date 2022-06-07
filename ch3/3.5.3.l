%{
%}

delim 	[ \t]
ws 			{delim}+

%%
{ws} { printf("%s", yytext); }
"float" { printf("double"); }
. { printf("%s", yytext); }
%%