-- Assuming you have 50 skills with IDs from 1 to 50 and 50 projects with IDs from 1 to 50.
INSERT INTO public."Skills_Projects" (skills_id, projects_id)
SELECT
  floor(random() * 50 + 1), -- Random skill ID between 1 and 50
  floor(random() * 50 + 1)  -- Random project ID between 1 and 50
FROM generate_series(1, 50); -- Generate 50 random associations
