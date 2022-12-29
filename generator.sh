#!/bin/bash

declare -i a=0
rm $1.hpp
touch $1.hpp
echo "#include <iostream>" >>$1.hpp
echo "using namespace std;" >>$1.hpp
echo class ${1^}{ >>$1.hpp
declare type
constructor=()
declare -A typename=([s]=string [i]=int [class]=class [i]=int [f]=float)

for i in $@; do
  if [ "$a" -lt 1 ]; then
    a=1
  else
    if [ $i == s -o $i == i -o $i == c -o $i == f -o $i == class ]; then
      type=$i
    else
      echo "  "${typename[$type]} "$i;" >>$1.hpp
    fi
  fi
done
a=0
echo "public:" >>$1.hpp
for i in $@; do
  if [ "$a" -lt 1 ]; then
    a=1
  else
    if [ $i == s -o $i == i -o $i == c -o $i == f -o $i == class ]; then
      type=$i
    else
      echo "  void set$i (${typename[$type]} $i){" >>$1.hpp
      echo "    this->$i = $i;" >>$1.hpp
      echo "  }" >>$1.hpp
      echo "  ${typename[$type]} get$i(){" >>$1.hpp
      echo "    return(this->$i);" >>$1.hpp
      echo "  }" >>$1.hpp
    fi
  fi
done
a=0
for i in $@; do
  if [ "$a" -lt 1 ]; then
    a=1
  else
    if [ $i == s -o $i == i -o $i == c -o $i == f -o $i == class ]; then
      constructor+=(${typename[$i]})
    else
      constructor+=($i)
      constructor+=(",")
    fi
  fi
done
a=0
echo "${1^}(){" >>$1.hpp
echo "}" >>$1.hpp
echo "${1^}(${constructor[@]}){" >>$1.hpp
for i in ${constructor[@]}; do
  if [ $i == "string" -o $i == "int" -o $i == "char" -o $i == "float" -o $i == "class" ]; then
    echo trash > /dev/null
  elif [ $i != "," ]; then
    echo "this->$i = $i;" >>$1.hpp
  fi
done
echo "  }" >>$1.hpp
echo "}" >>$1.hpp
