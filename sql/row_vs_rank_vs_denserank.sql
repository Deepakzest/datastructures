select 
      A.employee_name,
      A.salary,
      D.department_name,
      A.row_number,
      A.rank,
      A.dense_rank from
(
  select 
      employee_name,
      department_id,
      salary,
      row_number() over (partition by department_id order by salary desc) as row_number,
      rank() over (partition by department_id order by salary desc) as rank,
      dense_rank() over (partition by department_id order by salary desc) as dense_rank 
      from employees order by department_id
)A 
      join Departments D on 
      A.department_id=D.department_id

/*
┌───────────────┬────────┬─────────────────┬────────────┬───────┬────────────┐
│ employee_name │ salary │ department_name │ row_number │ rank  │ dense_rank │
│    varchar    │ int32  │     varchar     │   int64    │ int64 │   int64    │
├───────────────┼────────┼─────────────────┼────────────┼───────┼────────────┤
│ Arun          │ 120000 │ Engineering     │          1 │     1 │          1 │
│ Charan        │  95000 │ Engineering     │          2 │     2 │          2 │
│ Bala          │  85000 │ Engineering     │          3 │     3 │          3 │
│ Deepak        │  85000 │ Engineering     │          4 │     3 │          3 │
│ Priya         │ 130000 │ Data Science    │          1 │     1 │          1 │
│ Divya         │  90000 │ Data Science    │          2 │     2 │          2 │
│ Karthik       │  90000 │ Data Science    │          3 │     2 │          2 │
│ Meena         │  70000 │ Data Science    │          4 │     4 │          3 │
│ Rahul         │ 100000 │ Marketing       │          1 │     1 │          1 │
│ Sneha         │  75000 │ Marketing       │          2 │     2 │          2 │
│ Vijay         │  65000 │ Marketing       │          3 │     3 │          3 │
│ Anjali        │ 110000 │ Finance         │          1 │     1 │          1 │
│ Ramesh        │  80000 │ Finance         │          2 │     2 │          2 │
│ Kavya         │  95000 │ HR              │          1 │     1 │          1 │
│ Mohan         │  60000 │ HR              │          2 │     2 │          2 │
│ Suresh        │ 105000 │ Sales           │          1 │     1 │          1 │
│ Naveen        │  70000 │ Sales           │          2 │     2 │          2 │
│ Harish        │  70000 │ Sales           │          3 │     2 │          2 │
│ Lakshmi       │ 125000 │ Research        │          1 │     1 │          1 │
├───────────────┴────────┴─────────────────┴────────────┴───────┴────────────┤
│ 19 rows                                                          6 columns │
└────────────────────────────────────────────────────────────────────────────┘
*/

