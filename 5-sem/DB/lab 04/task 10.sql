SELECT odate, COUNT(cnum)
FROM public."Orders"
GROUP BY odate