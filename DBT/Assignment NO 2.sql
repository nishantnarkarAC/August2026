use db2;

create table Employee (
id int primary key,
name varchar(10),
age int ,
emaild varchar(20));

create table Dept (
did int,
dname varchar(10));

insert into Employee values (1, 'Nishant', 24, 'nishant@gmail.com',20000),
(2, 'Rahul', 25, 'rahul@gmail.com',57000),
(3, 'Ram', 44, 'ram@gamil.com',64000);

insert into Dept values (1, 'IT'),
(2, 'CS'),
(3, 'Mech');

alter table Dept
add column course varchar(20);

alter table Employee
add column salary int;


insert into Dept(did, dname) values (4, 'AIML'),
(5, 'ELE'),
(6, 'CDAC'),
(7, 'DS'),
(8, 'ENTC');

delete from Dept;

select * from dept;

Update Employee
set salary = 10000 where id = 3;

select * from Employee;

start transaction;
savepoint s1;

insert into Employee values (4, 'sham',22,'sham@gmail.com', 20000);

commit;

select * from Employee;

savepoint s2;

update Employee
set salary = 3000 where id  = 1;

commit;

savepoint s3;

update employee 
set age = 55 where id  = 2;

rollback to s3;

SET autocommit = 0;

START TRANSACTION;

SAVEPOINT s3;

UPDATE Employee
set salary = 25000
where id  = 2;

rollback to s3;

SAVEPOINT s4;

UPDATE Employee
set age = 11
where id  = 2;

rollback to s4;

commit;

truncate Employee;

select * from Employee where salary > 50000;

update Employee
set salary = salary + (salary * 0.1)
where id = 2;

select * from Employee;

select count(*) from Employee;
select count(*) from dept;

select max(salary)  from Employee;

select * from Employee order by salary desc limit 1 offset 1;

