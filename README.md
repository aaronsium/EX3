# EX3

# ![pageres](media/promo.jpg)

EX3 is an ‫‪interpreter‬‬ for unmanned aerial vehicle. 
The vehicle is a plane that fly's in the virtual space of the flight simulator ‫‪FlightGear. 

## Install

```
$ sudo add-apt-repository ppa:saiarot895/fligthgear
$ sudo apt-get update
$sudo apt-get install flightgear
```

## Usage

```
include "EX3.cpp"
```

## API

#### Lexer

Type: `object`

Lexer is reading a code from a file and rearrange
the code in a array of strings.  

#### parser

Type: `object`

Parser goes through the Lexer's array and activate
the command's in the array.

#### Command

Type: `Interface`

#### OpenServer

Type: `Command object`

OpenServer is opening a thread that run's a server.
The server is reading information that send by the
client ,the simulator, line by line.

#### ConnectCommand

Type: `Command object`

ConnectCommand is opening a thread, in the
thread we make connection to the simulator as
client that sending information line by line.

#### DefineVarCommand

Type: `Command object`

DefineVarCommand receive's an new variables of
the plane and declare them in the program.

#### SetVarCommand

Type: `Command object`

SetVarCommand initialize plane's variable.

#### SetVarCommand

Type: `Command object`

SetVarCommand initialize plane's variable.

#### ConditionParser

Type: `Command object`

ConditionParser is in charge of commands that 
their operation is conditional. the conditions are
if - `ifCommand`, while - `loopCommand`.

#### variables

- `varSim`: type unordered_map<string,Var*>.
            key- variable path, value- pointer to 
            SetVarCommand object.
            
- `varProgram`: type unordered_map<string,Var>. 
                key- variable name, value- SetVarCommand
                object.
                
- `commandMap`: unordered_map<string, Command*>.
                key- command's name, value- command.
                
##### expressions

In order to deal with expressions use classes from "EX1.cpp":
`BinaryOperator` `UnaryOperator` `UPlus` `UMinus` `Plus` `Minus` 
`Mul` `Div` `Var` `Value`