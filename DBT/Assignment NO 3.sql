use db2;

CREATE TABLE Department (
    dept_id INT PRIMARY KEY,
    dept_name VARCHAR(50),
    location VARCHAR(50)
);

INSERT INTO Department VALUES
(10, 'HR', 'Mumbai'),
(20, 'IT', 'Pune'),
(30, 'Finance', 'Delhi'),
(40, 'Marketing', 'Bangalore'),
(50, 'Sales', 'Hyderabad');

CREATE TABLE EEmployee (
    emp_id INT PRIMARY KEY,
    emp_name VARCHAR(50),
    job_title VARCHAR(50),
    salary DECIMAL(10,2),
    dept_id INT,
    FOREIGN KEY (dept_id) REFERENCES Department(dept_id)
);

INSERT INTO EEmployee VALUES
(101, 'Rahul Sharma', 'Manager', 60000.00, 10),
(102, 'Priya Patel', 'Developer', 45000.00, 20),
(103, 'Amit Verma', 'Accountant', 40000.00, 30),
(104, 'Sneha Rao', 'Designer', 42000.00, 40),
(105, 'Vikram Singh', 'Sales Executive', 35000.00, 50);

SELECT * FROM Department;

SELECT * FROM EEmployee;

select SUM(SALARY) as Total_salary FROM EEmployee;

select dept_id,avg(salary) from EEmployee group by dept_id; 

select dept_id,count(emp_id) as Total_number_of_employees from EEmployee group by dept_id;

INSERT INTO Department VALUES
(60, 'IT', 'Mumbai'),
(70, 'IT', 'Pune'),
(80, 'IT', 'Sangli'),
(90, 'IT', 'akola'),
(91, 'IT', 'Pune');

select dept_id from EEmployee having emp >5; 

INSERT INTO EEmployee VALUES
(106, 'Neha Joshi', 'Tester', 38000, 20),
(107, 'Rohan Patil', 'Developer', 50000, 20),
(108, 'Pooja Shah', 'Team Lead', 65000, 20),
(109, 'Karan Mehta', 'Support Engineer', 30000, 20),
(110, 'Sneha Kulkarni', 'Developer', 47000, 20);

SELECT dept_id, COUNT(*) AS total_employees
FROM EEmployee 
group by dept_id
having count(*) > 5;

select dept_id,count(*) from EEmployee;

select distinct location from Department;

select max(salary) from EEmployee;

select count(*) as total_Employee from EEmployee;

select * from EEmployee where emp_name like 'A%';

select * from EEmployee where emp_name like '%i';

select * from EEmployee where emp_name like '%ra%';

select * from EEmployee order by salary desc;

select * from EEmployee order by dept_id,salary desc;

select * from EEmployee where salary between 30000 and 60000;

select * from EEmployee where dept_id in(10,20,30);

ALTER TABLE EEmployee
ADD join_date DATE;

select * from EEmployee;

UPDATE EEmployee
SET join_date = '2020-01-15'
WHERE emp_id = 104;

UPDATE EEmployee
SET join_date = '2021-03-10'
WHERE emp_id = 102;

UPDATE EEmployee
SET join_date = '2023-07-01'
WHERE emp_id = 103;

UPDATE EEmployee
SET join_date = '2024-01-15'
WHERE emp_id = 104;

UPDATE EEmployee
SET join_date = '2024-03-10'
WHERE emp_id = 105;

UPDATE EEmployee
SET salary = 102000
WHERE emp_id = 107;

select* from EEmployee where join_date between '2020-01-01' and '2021-12-31';

select * from EEmployee where salary is null;

select * from EEmployee where salary is not null;

select SUM(SALARY) FROM EEmployee group by dept_id having sum(salary) > 100000;

select distinct emp_name from EEmployee;

select e.emp_name,d.dept_name, d.location
from EEmployee e
join Department d
on e.dept_id = d.dept_id
order by d.location in (
select location 
from Department 
group by location
having count(*) > 1);


UPDATE Department
SET location = 'Mumbai'
WHERE dept_id = 20;

SELECT COUNT(*)
FROM Department
WHERE location IN (
    SELECT location
    FROM Department
    GROUP BY location
    HAVING COUNT(*) > 1
);
