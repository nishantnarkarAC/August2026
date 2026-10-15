
CREATE TABLE student (
    student_id INT PRIMARY KEY,
    student_name VARCHAR(50),
    marks INT
);


INSERT INTO student (student_id, student_name, marks)
VALUES
(101, 'Amit', 85),
(102, 'Priya', 72),
(103, 'Rahul', 45),
(104, 'Sneha', 91),
(105, 'Rohan', 63),
(106, 'Neha', 78),
(107, 'Karan', 32),
(108, 'Pooja', 56);


delimiter //
create procedure check_even_odd(in num int)
begin
if mod(num,2) = 0 then
select 'even' as result ;
else
select 'odd' as result; 

end if;
end //
delimiter ;

call check_even_odd(25);
call check_even_odd(40);

delimiter //
create procedure calculate_interest(in principle int,in rate int,in s_time int)
begin
 declare simple_interest int;
set simple_interest = (principle*rate*s_time)/100;
select simple_interest as result;
end //
delimiter ;

call calculate_interest(10000,5,2);
call calculate_interest(25000,7,3);

delimiter //
create procedure calculate_grade(in student_id int, in student_name varchar(10), in marks int)
begin
declare grade varchar(10);
if marks is null then 
select 'marks are invalid' as result;

elseif marks >= 90 then 
set grade = 'A+';

elseif marks >= 80 then 
set grade = 'A';

elseif marks >= 70 then 
set grade = 'B';

elseif marks >= 60 then 
set grade = 'C';

elseif marks >= 50 then 
set grade = 'D';

else 
set grade = 'F';
end if;
select student_id as id,student_name as name, grade as result_grade;
end//

delimiter ;

drop procedure calculate_grade;

CALL calculate_grade(101, 'Amit', 85);
CALL calculate_grade(102, 'Priya', 72);
CALL calculate_grade(103, 'Rahul', 45);

delimiter //
create procedure calculate_bonus(in name varchar(10), in salary int)

begin 

declare bonus_p int;
declare bonus_amount int;
declare t_salary int;

if salary is null then 
select 'bench' as result;

elseif salary >= 100000 then
set bonus_p = 20;

elseif salary >= 50000 then
set bonus_p = 15;

elseif salary >= 30000 then
set bonus_p = 10;

else
set bonus_p = 5;

end if;

set bonus_amount = (salary * bonus_p)/100;

set t_salary = salary + bonus_amount;

select name as emp_name,
salary , bonus_p, bonus_amount ,
t_salary as total_salary;
end //
delimiter ;

CALL calculate_bonus('Amit', 120000);
CALL calculate_bonus('Priya', 65000);
CALL calculate_bonus('Rahul', 25000);


delimiter //
create procedure find_max(in a int, in b int, in c int)
begin
declare max_num int;

if a >= b and a>=c then
set max_num = a;

elseif b >= c and b>=a then
set max_num = b;

else
set max_num = c;

end if;

select max_num;

end //
delimiter ;

CALL find_max(25, 78, 45);
CALL find_max(100, 50, 75);
CALL find_max(30, 30, 20);
drop procedure find_max;

delimiter //
create procedure salary_analysis(in name varchar(10), in salary int)
begin 

declare category varchar(10);
declare allowance_p int;
declare allowance int;
declare f_salary int;

if salary >= 100000 then
set category = 'High'; 
set allowance_p = 20;

elseif salary >= 50000 then
set category = 'Medium' ;
set allowance_p = 15;

else
set category = 'Low' ;
set allowance_p = 10;

end if;

set allowance = (salary * allowance_p)/100;

set f_salary = salary + allowance;

select name, salary, category , allowance_p , allowance , f_salary;

end //
delimiter ;

drop procedure salary_analysis;

CALL salary_analysis('Amit', 120000);
CALL salary_analysis('Priya', 60000);
CALL salary_analysis('Rahul', 35000);


delimiter //
create procedure electricity_bill(in name varchar(10), in units int)
begin

declare total_bill int;

set total_bill = units * 2;

select name,units,total_bill;

end //
delimiter ;

CALL electricity_bill('Amit', 80);
CALL electricity_bill('Priya', 150);
CALL electricity_bill('Rahul', 350);
CALL electricity_bill('Sneha', 500);
