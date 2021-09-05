#!/usr/bin/env bash

rm ./cls/*.class

javac -d ./cls -sourcepath . *.java

java -cp ./cls MyClass
