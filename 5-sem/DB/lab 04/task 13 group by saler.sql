SELECT SUM(amt), snum FROM public."Orders"
WHERE amt > 100 
GROUP BY snum
HAVING SUM(amt) > 300;
