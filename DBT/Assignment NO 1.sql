use db1;
create table authors (author_id int primary key, name varchar(100), country varchar(50));
select * from authors;

create table books (
book_id int primary key, 
title varchar(150), 
author_id int,
publisher_year Year, 
avialable_copies int,
foreign  key(author_id) References authors(author_id));

create table member (member_id int primary key, name varchar(100), email varchar(100) unique, phone varchar(15));

create table borrow_records ( 
record_id int primary key,
member_id int,
book_id int,
borrow_date date,
return_date date,
foreign key(member_id) references member(member_id),
foreign key(book_id) references books(book_id));

alter table books
add column genre varchar(50);

drop table borrow_records;

select * from borrow_records;

insert into authors values (1,'Harry Potter', 'Us'),
(2, 'Doremon', 'Dubai'),
(3, 'Wings of fire', 'india');

insert into books(book_id, title, author_id, publisher_year,avialable_copies) values(01,'AA',1,1998,44),
(02,'EE',2,1998,47),
(03,'BB',3,1947,78),
(04,'CC',1,1975,99),
(05,'DD',2,2026,45);

insert into member values(91, 'Nishant', 'nish@gmail.com', '7276337341'),
(92, 'Ram', 'ram@gmail.com', '9420337341'),
(93, 'sham', 'sham@gmail.com', '83786337341');

insert into borrow_records values (41,91,1,'2026-05-04','2026-05-24'),
(42,92,1,'2026-09-04','2026-09-20'),
(43,93,1,'2026-08-04','2026-08-20'),
(44,92,1,'2026-07-04','2026-07-21');

select * from books where publisher_year > 2015;

select name from member where title = 'Doremon';

select * from member;

delete from member where member_id = 93;

select * from books;

update books
set avialable_copies = avialable_copies - 1
where book_id = 1;

select * from borrow_records;

delete from borrow_records
where member_id = 93;

update books
set title = 'Kung fu Panda' 
where book_id = 1;

select b.book_id, b.title, b.author_id, b.publisher_year, b.avialable_copies, b.genre, m.name
from books as b, member as m; 

delete from borrow_records 
where publisher_year < 2000;

