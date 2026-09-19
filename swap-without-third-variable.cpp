int a = 10, b = 20;

a = a ^ b; // a becomes 30
b = a ^ b; // b becomes 10
a = a ^ b; // a becomes 20


int a = 10, b = 20;

a = a + b; // a becomes 30 (10 + 20)
b = a - b; // b becomes 10 (30 - 20, original value of a)
a = a - b; // a becomes 20 (30 - 10, original value of b)
