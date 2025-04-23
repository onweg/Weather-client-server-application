--
-- PostgreSQL database dump
--

-- Dumped from database version 14.17 (Homebrew)
-- Dumped by pg_dump version 17.0

-- Started on 2025-04-23 17:17:27 MSK

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET transaction_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 3667 (class 1262 OID 57389)
-- Name: myapp; Type: DATABASE; Schema: -; Owner: user
--

CREATE DATABASE myapp WITH TEMPLATE = template0 ENCODING = 'UTF8' LOCALE_PROVIDER = libc LOCALE = 'C';


ALTER DATABASE myapp OWNER TO user;

\connect myapp

SET statement_timeout = 0;
SET lock_timeout = 0;
SET idle_in_transaction_session_timeout = 0;
SET transaction_timeout = 0;
SET client_encoding = 'UTF8';
SET standard_conforming_strings = on;
SELECT pg_catalog.set_config('search_path', '', false);
SET check_function_bodies = false;
SET xmloption = content;
SET client_min_messages = warning;
SET row_security = off;

--
-- TOC entry 4 (class 2615 OID 2200)
-- Name: public; Type: SCHEMA; Schema: -; Owner: user
--

-- *not* creating schema, since initdb creates it


ALTER SCHEMA public OWNER TO user;

SET default_tablespace = '';

SET default_table_access_method = heap;

--
-- TOC entry 210 (class 1259 OID 57391)
-- Name: users; Type: TABLE; Schema: public; Owner: user
--

CREATE TABLE public.users (
    id integer NOT NULL,
    username character varying(50) NOT NULL,
    password_hash character varying(255) NOT NULL
);


ALTER TABLE public.users OWNER TO user;

--
-- TOC entry 209 (class 1259 OID 57390)
-- Name: users_id_seq; Type: SEQUENCE; Schema: public; Owner: user
--

CREATE SEQUENCE public.users_id_seq
    AS integer
    START WITH 1
    INCREMENT BY 1
    NO MINVALUE
    NO MAXVALUE
    CACHE 1;


ALTER SEQUENCE public.users_id_seq OWNER TO user;

--
-- TOC entry 3669 (class 0 OID 0)
-- Dependencies: 209
-- Name: users_id_seq; Type: SEQUENCE OWNED BY; Schema: public; Owner: user
--

ALTER SEQUENCE public.users_id_seq OWNED BY public.users.id;


--
-- TOC entry 3516 (class 2604 OID 57394)
-- Name: users id; Type: DEFAULT; Schema: public; Owner: user
--

ALTER TABLE ONLY public.users ALTER COLUMN id SET DEFAULT nextval('public.users_id_seq'::regclass);


--
-- TOC entry 3661 (class 0 OID 57391)
-- Dependencies: 210
-- Data for Name: users; Type: TABLE DATA; Schema: public; Owner: user
--

COPY public.users (id, username, password_hash) FROM stdin;
1	login	5f4dcc3b5aa765d61d8327deb882cf99
3	login1	5f4dcc3b5aa765d61d8327deb882cf99
4	login12	5f4dcc3b5aa765d61d8327deb882cf99
5	admin	81dc9bdb52d04dc20036dbd8313ed055
6	admin2	827ccb0eea8a706c4c34a16891f84e7b
7	login1234	7c6a180b36896a0a8c02787eeafb0e4c
8	1	c4ca4238a0b923820dcc509a6f75849b
9	W	03c7c0ace395d80182db07ae2c30f034
10	2	c81e728d9d4c2f636f067f89cc14862c
11	А	c15c49a8f55a3dd0da7c8eda0e7485f9
12	Q	7694f4a66316e53c8cdd9d9954bd611d
13	Й	5af57ea0892641f24c731d1e4e27cee4
14	11	a87ff679a2f3e71d9181a67b7542122c
15	Ено	55caa955334ab696e71a43f7a41ce0fb
\.


--
-- TOC entry 3670 (class 0 OID 0)
-- Dependencies: 209
-- Name: users_id_seq; Type: SEQUENCE SET; Schema: public; Owner: user
--

SELECT pg_catalog.setval('public.users_id_seq', 15, true);


--
-- TOC entry 3518 (class 2606 OID 57396)
-- Name: users users_pkey; Type: CONSTRAINT; Schema: public; Owner: user
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_pkey PRIMARY KEY (id);


--
-- TOC entry 3520 (class 2606 OID 57398)
-- Name: users users_username_key; Type: CONSTRAINT; Schema: public; Owner: user
--

ALTER TABLE ONLY public.users
    ADD CONSTRAINT users_username_key UNIQUE (username);


--
-- TOC entry 3668 (class 0 OID 0)
-- Dependencies: 4
-- Name: SCHEMA public; Type: ACL; Schema: -; Owner: user
--

REVOKE USAGE ON SCHEMA public FROM PUBLIC;
GRANT ALL ON SCHEMA public TO PUBLIC;


-- Completed on 2025-04-23 17:17:27 MSK

--
-- PostgreSQL database dump complete
--

