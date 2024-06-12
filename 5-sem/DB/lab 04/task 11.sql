SELECT odate, COUNT(cnum)
FROM public."Orders"
WHERE snum IN(
	SELECT snum FROM public."Salers"
	WHERE comm > 0.08)
GROUP BY odate


