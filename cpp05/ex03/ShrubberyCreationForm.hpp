#pragma once

#include "Bureaucrat.hpp"
#include <fstream>

#define MY_ASCII_ART \
"         .        +          .      .          .\n" \
"     .            _        .                    .\n" \
"  ,              /;-._,-.____        ,-----.__\n" \
" ((        .    (_:#::_.:::. `-._   /:, /-._, `._,\n" \
"  `                 \\   _|`\"=:_::.`.);  \\ __/ /\n" \
"                      ,    `./  \\:. `.   )==-'  .\n" \
"    .      ., ,-=-.  ,\\, +#./`   \\:.  / /           .\n" \
".           \\/:/`-' , ,\\ '` ` `   ): , /_  -o\n" \
"       .    /:+- - + +- : :- + + -:'  /(o-) \\)     .\n" \
"  .      ,=':  \\    ` `/` ' , , ,:' `'--\".---._/`7\n" \
"   `.   (    \\: \\,-._` ` + '\\, ,'   _,--._,---\":.__/\n" \
"              \\:  `  X` _| _,\\/\"   .-'\n" \
".               \":._:`\\____  /:'  /      .           .\n" \
"                    \\::.  :\\/:'  /              +\n" \
"   .                 `.:.  /:'  }      .\n" \
"           .           ):_(:;   \\           .\n" \
"                      /:. _/ ,  |\n" \
"                   . (|::.     ,`                  .\n" \
"     .                |::.    {\\\n" \
"                      |::.\\  \\ `.\n" \
"                      |:::(\\    |\n" \
"              O       |:::/{ }  |                  (o\n" \
"               )  ___/#\\::`/ (O \"==._____   O, (O  /`\n" \
"          ~~~w/w~\"~~,\\` `:/,-(~`\"~~~~~~~~\"~o~\\~/~w|/~\n" \
"dew   ~~~~~~~~~~~~~~~~~~~~~~~\\\\W~~~~~~~~~~~~\\|/~~"



class ShrubberyCreationForm : public AForm
{
	private:
		std::string target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string );
		ShrubberyCreationForm(const ShrubberyCreationForm &);
		ShrubberyCreationForm &operator = (const ShrubberyCreationForm &);
		~ShrubberyCreationForm();
		std::string getTarget();
		void execute(Bureaucrat const &b) const;
};