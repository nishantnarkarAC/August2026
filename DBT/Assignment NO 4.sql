create database db3;
use db3;

create table Department (
dept_id int primary key,
dept_name varchar(20),
location varchar(20));

create table Employee (
emp_id int primary key,
emp_name varchar(20),
dept_id int,
salary int,
joining_date date,
constraint fk_dept_emp
foreign key(dept_id) references Department(dept_id));

create table Project (
project_id int primary key,
project_name varchar(20),
dept_id int,
budget int,
constraint fk_dept_project
foreign key(dept_id) references Department(dept_id));

INSERT INTO Department (dept_id, dept_name, location) VALUES
(1, 'HR', 'New York'),
(2, 'Engineering', 'San Francisco'),
(3, 'Sales', 'Chicago'),
(4, 'Marketing', 'Boston'),
(5, 'Finance', 'New York');

INSERT INTO Employee (emp_id, emp_name, dept_id, salary, joining_date) VALUES
(101, 'Alice Smith', 2, 85000, '2022-01-15'),
(102, 'Bob Jones', 1, 60000, '2021-11-20'),
(103, 'Charlie Brown', 3, 72000, '2023-03-10'),
(104, 'Diana Prince', 2, 95000, '2020-07-05'),
(105, 'Evan Wright', 4, 65000, '2023-06-12');

INSERT INTO Project (project_id, project_name, dept_id, budget) VALUES
(201, 'Cloud Migration', 2, 120000),
(202, 'Recruitment Portal', 1, 45000),
(203, 'Q3 Sales Campaign', 3, 80000),
(204, 'Brand Redesign', 4, 50000),
(205, 'Security Audit', 2, 60000);

update Project
set budget = 45000
where project_id = 204;

select emp_name,dept_name
from employee as e
inner join department as d
on e.dept_id = d.dept_id;

select* from Employee;
select * from Department;

select *
from Employee
cross join Project;

select * from Employee
cross join Department;


select *
from Employee
natural join Department;

select e.emp_name, d.dept_id, d.dept_name, d.location 
from Employee e
left join Department d
on e.dept_id = d.dept_id;

select * 
from Employee e
right join Department d
on e.dept_id = d.dept_id;

create table Emp_backup (
emp_id int primary key,
emp_name varchar(20),
dept_id int,
salary int,
joining_date date,
constraint fk_dept_emp_backup
foreign key(dept_id) references Department(dept_id));

insert into Emp_backup
select * from Employee;

create table Project_archive as
select* from Project;

alter table Employee
modify column emp_id int auto_increment;

select emp_id,emp_name, salary 
from Employee 
where salary > (
select avg(salary) from Employee);

select * from Employee
where dept_id in (1,3);

select * from department
where dept_id in
(select dept_id from Employee
group by dept_id
having count(*) > 1);

select * from Employee
where salary = (
select max(salary) from Employee);

select d.dept_name as dept1, e.dept_name as dept2, d.location
from Department d
join Department e
on d.location = e.location
where d.dept_id <> e.dept_id;

select e.emp_name as emp1, d.emp_name as emp2, e.emp_id
from Employee e
join Employee d
on d.dept_id = e.dept_id
where d.emp_id < e.emp_id;

select p.project_name as project1, e.project_name as project2, p.budget
from Project p
join Project e
on p.budget = e.budget
where p.project_id < e.project_id;

