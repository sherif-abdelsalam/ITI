
import nodemailer from "nodemailer";
import { emailTemplate } from "./emailTemplate.js"
import jwt from "jsonwebtoken";
export const sendEmail = async (email) => {
    const transporter = nodemailer.createTransport({
        service: "gmail",
        auth: {
            user: process.env.MY_EMAIL,
            pass: process.env.GMAIL_PASSWORD,
        },
    });
    
    const emailToken = jwt.sign(email, process.env.JWT_SECRET);


    const info = await transporter.sendMail({
        from: `From <${process.env.MY_EMAIL}>`,
        to: email,
        subject: "Verify Your Email",
        html: emailTemplate(emailToken),
    });

    console.log("Message sent:", info.messageId);
}
