UPDATE public."Irrelevant_Skills"
SET id = public."Skills".id  

FROM public."Developers_Skills"   
INNER JOIN public."Skills" ON public."Developers_Skills".skills_id = public."Skills".id;
 