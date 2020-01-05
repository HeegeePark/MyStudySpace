set @myVar1 = 5;
set @myVar2 = 3;
set @myVar3 = 4.25;
set @myVar4 = 'singer name ==>';

select @myVar1;
select @myVar2+@myvar3;
select @myVar4, name from usertbl where height >180 limit 3;
select @myVar4, name from usertbl where height >180 limit @myvar2;

prepare myQuery from 'SELECT Name, height FROM usertbl ORDER BY height limit ?';
execute myQuery using @myvar2;


select avg(amount) as 'avg amount' from buytbl;
select cast(avg(amount) as signed integer) as 'avg amount' from buytbl;
select convert(avg(amount), signed integer) as 'avg amount' from buytbl;

select cast('2020$12$12' as date);
select cast('2020/12/12' as date);
select cast('2020%12%12' as date);
select cast('2020@12@12' as date);

select num, concat(cast(price as char(10)),'x', cast(amount as char(4)),'=') as 'price X amount', price*amount as 'total price' from buytbl;

select '100'+'200';
select concat('100','200');
select concat(100,'200');
#no 2ㄹㅗ ㅇㅣㄴㅅㅣㄱㅎㅏㅁ true 1, false 0
select 1 > '2mega';
select 1 < '2';
select 3 > '2MEGA';
# ㅇㅕㅇㅇㅓㄱㅏ ㄴㅏㅇㅗㄹㅅㅣ 0ㅇㅡㄹㅗ ㅇㅣㄴㅅㅣㄱㅎㅏㅁ
select 0 = 'mega2';


select if(100>200, 'true','false');
select ifnull(null,'it is null'),ifnull(100,'itisnull');
select nullif(100,100),ifnull(200,100);

select case 10
		when 1 then 'one'
		when 5 then 'five'
        when 10 then 'ten'
        else 'idontknow'
        end;
        

select ascii('A'), char(65);

select bit_length('abc'), char_length('abc'),length('abc');
select bit_length('가나다'), char_length('가나다'),length('가나다');

select concat_ws('/', '2020','01','01');
select concat_ws('-', '2020','01','01');

#ㄷㅜㅂㅓㄴㅉㅐ ㄱㅓㅅ
select elt(2, 'one', 'two', 'three');
#ㅁㅐㄴㅊㅓㅇㅡㅁ ㅁㅜㄴㅈㅏㄱㅏ ㅁㅕㅊㅂㅓㄴㅈㅐㅇㅔ ㄴㅏㅇㅗㄴㅡㄴㅑ
select field('two', 'one', 'two', 'three');
#ㅁㅐㄴㅊㅓㅇㅡㅁ ㅁㅜㄴㅈㅏㄱㅏ ㅁㅜㄴㅈㅏㅇㅕㄹㅇㅡㅣ ㅁㅕㅊㅂㅓㄴㅈㅐㅇㅔ ㄴㅏㅇㅗㄴㅡㄴㅑ
select find_in_set('two', 'one,two,three');
#ㄷㅜㅣㅇㅔㅇㅣㅆㄴㅡㄴ ㅁㅜㄴㅈㅏㄱㅏ ㅇㅏㅍㅇㅔㅇㅣㅆㄴㅡㄴ ㅇㅕㄴㄱㅕㄹㄷㅗㅣㄴ ㅁㅜㄴㅈㅏㅇㅕㄹㅇㅔ ㅁㅕㅊㅂㅓㄴㄸㅐㅇㅔ ㅈㅗㄴㅈㅐㅎㅏㄴㅑ
select instr('onetwothree','two');
#ㅇㅏㅍㅇㅔㅇㅣㅆㄴㅡㄴ ㅁㅜㄴㅈㅏㄱㅏ ㄷㅜㅣㅇㅔㅇㅣㅆㄴㅡㄴ ㅇㅕㄴㄱㅕㄹㄷㅗㅣㄴ ㅁㅜㄴㅈㅏㅇㅕㄹㅇㅔ ㅁㅕㅊㅂㅓㄴㄸㅐㅇㅔ ㅈㅗㄴㅈㅐㅎㅏㄴㅑ
select locate('two', 'onetwothree');


select format(123456.123456,4);

select bin(31),hex(31),oct(31);

select insert('abcdefghi', 3, 4, '@@@@'),
		insert('abcdefghi', 3, 2, '@@@@');
        
select left('abcdefghi', 3),
		right('abcdefghi',3);
        
select lcase('abcdEFGH'),ucase('abcdEFGH');
select lower('abcdEFGH'),upper('abcdEFGH');

select lpad('thisis', 8, '##'), rpad('thisis', 8, '##'); 
select ltrim('         thisis'), rtrim('thisis         ');
select trim('          thisis            '), trim(both 'u' from 'uuuuufunnyuuuuu');

select repeat('thisis',3);
select replace('thisis MYSQL','thisis','이것이');
select reverse('MYSQL');
select concat('이것이', space(10), 'MYSQL');

select substring('koreamansae', 3,2);
select substring_index('cafe.naver.com','.',2);
select substring_index('cafe.naver.com','.',-2);

select abs(-100);
select ceiling(4.7), floor(4.7), round(4.7);
select conv('AA',16,2), conv(100,10,8);
select degrees(pi()), radians(180);
select mod(157,10), 157%10, 157 mod 10;
select pow(2,3), sqrt(9);
select sign(100), sign(0), sign(-100.123);
select truncate(1234.12345,2), truncate(1234.12345,-2);

select adddate('2020-01-01', interval 31 day),
	   adddate('2020-01-01', interval 1 month);
select subdate('2020-01-01', interval 31 day),
	   subdate('2020-01-01', interval 1 month);

select addtime('2020-01-01 23:59:59','1:1:1'), addtime('15:00:00','2:10:10');
select subtime('2020-01-01 23:59:59','1:1:1'), subtime('15:00:00','2:10:10');

select year(curdate()), month(curdate()), dayofmonth(curdate());
select hour(curtime()), minute(curtime()), second(curtime()),microsecond(curtime());
select date(now()), time(now());

select datediff('2020-01-01', now()), timediff('23:23:59','12:11:10');
select dayofweek(curdate()), monthname(curdate()), dayofyear(curdate());
select last_day('2020-02-01');

select makedate(2020,32);
select maketime(12,11,10);
select period_add(202001,11),period_diff(202001,201812);

select quarter('2020-07-07');
select time_to_sec('12:11:10');

select current_user, database();

select*from usertbl;
select found_rows();

select*from buytbl;

update buytbl set price = price*2;
select row_count();

select sleep(5);
select 'after 5sec'