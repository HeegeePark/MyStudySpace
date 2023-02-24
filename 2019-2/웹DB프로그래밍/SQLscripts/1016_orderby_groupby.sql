use sqlDB;

select * from userTBL;
select * from buyTBL;

# 구매 테이블에서 사용자들의 구매 수량을 ID 순서대로 출력
select userID, amount from buytbl order by userID;

# ID value에 따라 구매 수량 합한 값 출력
# as '출력할 컬럼 이름'
select userID as '사용자 아이디', sum(amount) as '총구매 개수' from buytbl group by userID;

select userID as '사용자 아이디', sum(price*amount) as '총 구매액' from buytbl group by userID;
# 총 구매액이 높운순
# order by A desc : A를 내림차순으로 정렬
select userID as '사용자 아이디', sum(price*amount) as '총 구매액' from buytbl group by userID order by sum(price*amount) desc;