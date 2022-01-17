import dotenv from 'dotenv';

dotenv.config({ path: '../.env' });

export const USER_ID = process.env.USER_ID;

export const USER_PW = process.env.USER_PW;
