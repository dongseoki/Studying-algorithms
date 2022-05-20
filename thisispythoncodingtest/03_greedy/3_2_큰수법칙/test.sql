

SELECT 업무종류테이블.업무_종류코드, 업무_종류명
(
    SELECT 업무코드
    FROM 직원
    INNER JOIN 업무
    ON 직원.직원코드 = 업무.담당자코드
    WHERE 
        직원.직원명 = '박현준'
)  AS TB1
INNER JOIN 업무_업무종류
ON TB1.업무코드=업무_업무종류.업무코드
LEFT OUTER JOIN 업무종류테이블
ON 업무_업무종류.업무_종류코드=업무종류테이블.업무_종류코드