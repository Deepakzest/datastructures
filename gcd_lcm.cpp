int gcd(int a,int b)
{
  return (b==0:a?gcd(a,b%a);
}

int lcm(int a,int b)
{
  return a/gcd(a,b)*b;
}
