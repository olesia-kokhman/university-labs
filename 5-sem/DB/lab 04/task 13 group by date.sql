SELECT SUM(amt), odate FROM public."Orders"
WHERE amt > 100 
GROUP BY odate
HAVING SUM(amt) > 300;

