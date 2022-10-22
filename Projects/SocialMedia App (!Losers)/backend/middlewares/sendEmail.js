const nodeMailer=require('nodemailer');

exports.sendEmail=async (options)=>{
    var transporter = nodeMailer.createTransport({
        host: "smtp.mailtrap.io",
        port: 2525,
        auth: {
          user: "59857befbf4eab",
          pass: "2ffec710592553"
        }
      });
    const mailOptions={
        from:"shivam@gmail.com",
        to:options.email,
        subject:options.subject,
        text:options.message,
    }
    await transporter.sendMail(mailOptions);
}