INSERT INTO public."Projects" (id, name, description, length_in_days, budget, started_at, status, lead_id, sale_id, sale_rate)
VALUES
(1, 'Website Redesign', 'Redesign of company website', 30, 5000, '2023-10-01', 'In Progress', 1, 1, 1.0),
(2, 'E-commerce Platform', 'Development of an e-commerce platform', 45, 7500, '2023-10-02', 'Completed', 2, 2, 1.1),
(3, 'Mobile App Development', 'Building a mobile app for iOS and Android', 60, 10000, '2023-10-03', 'In Progress', 3, 3, 1.2),
(4, 'Content Creation', 'Content creation and marketing campaign', 30, 5000, '2023-10-04', 'Completed', 4, 4, 1.3),
(5, 'Software Upgrade', 'Upgrading existing software systems', 45, 7500, '2023-10-05', 'In Progress', 5, 5, 1.4),
(6, 'Social Media Marketing', 'Marketing through social media channels', 60, 10000, '2023-10-06', 'Completed', 6, 1, 1.5),
(7, 'Graphic Design Project', 'Designing marketing materials and graphics', 30, 5000, '2023-10-07', 'In Progress', 7, 2, 1.0),
(8, 'Product Launch', 'Launch of a new product line', 45, 7500, '2023-10-08', 'Completed', 8, 3, 1.1),
(9, 'Database Optimization', 'Optimizing database performance', 60, 10000, '2023-10-09', 'In Progress', 9, 4, 1.2),
(10, 'Marketing Campaign', 'Digital marketing and advertising', 30, 5000, '2023-10-10', 'Completed', 10, 5, 1.3),
(11, 'SEO Improvement', 'Search engine optimization for website', 45, 7500, '2023-10-11', 'In Progress', 11, 1, 1.4),
(12, 'App Integration', 'Integration of third-party apps', 60, 10000, '2023-10-12', 'Completed', 12, 2, 1.5),
(13, 'Content Management', 'Content management and publishing', 30, 5000, '2023-10-13', 'In Progress', 13, 3, 1.0),
(14, 'Marketing Strategy', 'Development of marketing strategy', 45, 7500, '2023-10-14', 'Completed', 14, 4, 1.1),
(15, 'Web Application', 'Building a web-based application', 60, 10000, '2023-10-15', 'In Progress', 15, 5, 1.2),
(16, 'Video Production', 'Production of promotional videos', 30, 5000, '2023-10-16', 'Completed', 16, 1, 1.3),
(17, 'Software Maintenance', 'Ongoing software maintenance', 45, 7500, '2023-10-17', 'In Progress', 17, 2, 1.4),
(18, 'Brand Redesign', 'Rebranding and logo redesign', 60, 10000, '2023-10-18', 'Completed', 18, 3, 1.5),
(19, 'Data Analysis', 'Data analysis and reporting', 30, 5000, '2023-10-19', 'In Progress', 19, 4, 1.0),
(20, 'Event Planning', 'Planning and organization of corporate events', 45, 7500, '2023-10-20', 'Completed', 20, 5, 1.1),
(21, 'UI/UX Design', 'User interface and user experience design', 60, 10000, '2023-10-21', 'In Progress', 21, 1, 1.2),
(22, 'Market Research', 'Market research and analysis', 30, 5000, '2023-10-22', 'Completed', 22, 2, 1.3),
(23, 'Customer Support', 'Customer support and service', 45, 7500, '2023-10-23', 'In Progress', 23, 3, 1.4),
(24, 'Product Testing', 'Quality testing of new products', 60, 10000, '2023-10-24', 'Completed', 24, 4, 1.5),
(25, 'Content Management', 'Content management and publishing', 30, 5000, '2023-10-25', 'In Progress', 25, 5, 1.0),
(26, 'IT Infrastructure', 'Upgrade of IT infrastructure', 45, 7500, '2023-10-26', 'Completed', 26, 1, 1.1),
(27, 'Market Expansion', 'Expansion into new markets', 60, 10000, '2023-10-27', 'In Progress', 27, 2, 1.2),
(28, 'Product Launch', 'Launch of a new product line', 30, 5000, '2023-10-28', 'Completed', 28, 3, 1.3),
(29, 'Database Optimization', 'Optimizing database performance', 45, 7500, '2023-10-29', 'In Progress', 29, 4, 1.4),
(30, 'Marketing Campaign', 'Digital marketing and advertising', 60, 10000, '2023-10-30', 'Completed', 30, 5, 1.5),
(31, 'SEO Improvement', 'Search engine optimization for website', 30, 5000, '2023-10-31', 'In Progress', 31, 1, 1.0),
(32, 'App Integration', 'Integration of third-party apps', 45, 7500, '2023-11-01', 'Completed', 32, 2, 1.1),
(33, 'Content Management', 'Content management and publishing', 60, 10000, '2023-11-02', 'In Progress', 33, 3, 1.2),
(34, 'Marketing Strategy', 'Development of marketing strategy', 30, 5000, '2023-11-03', 'Completed', 34, 4, 1.3),
(35, 'Web Application', 'Building a web-based application', 45, 7500, '2023-11-04', 'In Progress', 35, 5, 1.4),
(36, 'Video Production', 'Production of promotional videos', 60, 10000, '2023-11-05', 'Completed', 36, 1, 1.5),
(37, 'Software Maintenance', 'Ongoing software maintenance', 30, 5000, '2023-11-06', 'In Progress', 37, 2, 1.0),
(38, 'Brand Redesign', 'Rebranding and logo redesign', 45, 7500, '2023-11-07', 'Completed', 38, 3, 1.1),
(39, 'Data Analysis', 'Data analysis and reporting', 60, 10000, '2023-11-08', 'In Progress', 39, 4, 1.2),
(40, 'Event Planning', 'Planning and organization of corporate events', 30, 5000, '2023-11-09', 'Completed', 40, 5, 1.3),
(41, 'UI/UX Design', 'User interface and user experience design', 60, 10000, '2023-11-10', 'In Progress', 41, 1, 1.4),
(42, 'Market Research', 'Market research and analysis', 30, 5000, '2023-11-11', 'Completed', 42, 2, 1.5),
(43, 'Customer Support', 'Customer support and service', 45, 7500, '2023-11-12', 'In Progress', 43, 3, 1.0),
(44, 'Product Testing', 'Quality testing of new products', 60, 10000, '2023-11-13', 'Completed', 44, 4, 1.1),
(45, 'IT Infrastructure', 'Upgrade of IT infrastructure', 30, 5000, '2023-11-14', 'In Progress', 45, 5, 1.2),
(46, 'Market Expansion', 'Expansion into new markets', 45, 7500, '2023-11-15', 'Completed', 46, 1, 1.3),
(47, 'Product Launch', 'Launch of a new product line', 60, 10000, '2023-11-16', 'In Progress', 47, 2, 1.4),
(48, 'Database Optimization', 'Optimizing database performance', 30, 5000, '2023-11-17', 'Completed', 48, 3, 1.5),
(49, 'Marketing Campaign', 'Digital marketing and advertising', 45, 7500, '2023-11-18', 'In Progress', 49, 4, 1.0),
(50, 'SEO Improvement', 'Search engine optimization for website', 60, 10000, '2023-11-19', 'Completed', 50, 5, 1.1);
