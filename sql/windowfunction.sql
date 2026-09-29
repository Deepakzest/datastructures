select 
  A.employee_name,
  A.salary,
  d.department_name,
  A.department_avg from departments d 
  join
(
  select 
  employee_name,
  department_id,
  salary,avg(salary) over( partition by department_id) as department_avg 
  from Employees order by department_avg desc
)A on d.department_id=A.department_id


/*
┌───────────────┬────────┬─────────────────┬───────────────────┐
│ employee_name │ salary │ department_name │  department_avg   │
│    varchar    │ int32  │     varchar     │      double       │
├───────────────┼────────┼─────────────────┼───────────────────┤
│ Suresh        │ 105000 │ Sales           │ 81666.66666666667 │
│ Naveen        │  70000 │ Sales           │ 81666.66666666667 │
│ Harish        │  70000 │ Sales           │ 81666.66666666667 │
│ Rahul         │ 100000 │ Marketing       │           80000.0 │
│ Sneha         │  75000 │ Marketing       │           80000.0 │
│ Vijay         │  65000 │ Marketing       │           80000.0 │
│ Kavya         │  95000 │ HR              │           77500.0 │
│ Mohan         │  60000 │ HR              │           77500.0 │
│ Lakshmi       │ 125000 │ Research        │          125000.0 │
│ Arun          │ 120000 │ Engineering     │           96250.0 │
│ Bala          │  85000 │ Engineering     │           96250.0 │
│ Charan        │  95000 │ Engineering     │           96250.0 │
│ Deepak        │  85000 │ Engineering     │           96250.0 │
│ Priya         │ 130000 │ Data Science    │           95000.0 │
│ Divya         │  90000 │ Data Science    │           95000.0 │
│ Karthik       │  90000 │ Data Science    │           95000.0 │
│ Meena         │  70000 │ Data Science    │           95000.0 │
│ Anjali        │ 110000 │ Finance         │           95000.0 │
│ Ramesh        │  80000 │ Finance         │           95000.0 │
├───────────────┴────────┴─────────────────┴───────────────────┤
│ 19 rows                                            4 columns │
└──────────────────────────────────────────────────────────────┘
*/
