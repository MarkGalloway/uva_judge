#!/bin/sh

cp DataStructures/UVa10226.C Solutions
cp DataStructures/UVa10608.C Solutions
cp DataStructures/UVa10815.C Solutions
cp DataStructures/UVa11402.C Solutions
cp DataStructures/UVa00655.C Solutions

cp String/UVa00856.C Solutions
cp String/UVa10374.C Solutions
cp String/UVa11475.C Solutions
cp String/UVa11512.C Solutions
cp String/UVa11837.C Solutions

cp Backtracking/Uva00729.C Solutions

cp GraphTraversal/UVa10672.C Solutions

cp DynamicProgramming/Uva00231.C Solutions
cp DynamicProgramming/Uva10819.C Solutions
cp DynamicProgramming/Uva00674.C Solutions
cp DynamicProgramming/Uva10003.C Solutions

tar -cvzf solutions.tgz Solutions/UVa*

scp solutions.tgz mgallowa@ug00.cs.ualberta.ca: