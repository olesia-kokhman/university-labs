INSERT INTO public."Projects_Developers" (id, projects_id, developers_id)
SELECT
  s.a,
  floor(random() * 50 + 1), -- Random skill ID between 1 and 50
  floor(random() * 50 + 1)  -- Random project ID between 1 and 50
FROM generate_series(1, 50) AS s(a); -- Generate 50 random associations
