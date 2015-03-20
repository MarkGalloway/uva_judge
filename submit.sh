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

cp Sorting/UVa10327.C Solutions
cp Sorting/UVa10026.C Solutions
cp Sorting/UVa10810.C Solutions
cp Sorting/UVa10905.C Solutions
cp Sorting/UVa00612.C Solutions

cp Arithmetic/UVa11955.C Solutions
cp Arithmetic/UVa10689.C Solutions
cp Arithmetic/UVa10655.C Solutions

cp Backtracking/UVa00729.C Solutions
cp Backtracking/UVa00193.C Solutions
cp Backtracking/UVa00750.C Solutions
cp Backtracking/UVa11195.C Solutions

cp GraphTraversal/UVa10672.C Solutions

cp DynamicProgramming/UVa00231.C Solutions
cp DynamicProgramming/UVa10819.C Solutions
cp DynamicProgramming/UVa00674.C Solutions
cp DynamicProgramming/UVa10003.C Solutions
cp DynamicProgramming/UVa00216.C Solutions

cp Other/UVa1266.C Solutions

tar -cvzf solutions.tgz Solutions/UVa*

scp solutions.tgz mgallowa@ug00.cs.ualberta.ca: