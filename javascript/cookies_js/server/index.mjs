import express from 'express';
import cookieParser from 'cookie-parser';

const PORT = 5090;
const Cookies_Signed = "我是一隻夢";

const app = express();

app.use(express.json());
app.use(cookieParser(Cookies_Signed));

app.get("/GetCookieUnSigned", (req, res) => {
    res.cookie("test", "message", {
        maxAge: 1000 * 60, // 60秒
        sameSite: 'strict', // 防止 CSRF 攻擊
        httpOnly: true, // 禁止 JS 訪問
        secure: false, // 在本地測試設置為 false
        signed: false // 不加密
    });
    return res.status(200).send("Unsigned Cookie has been set");
});

app.get("/GetCookieSigned", (req, res) => {
    res.cookie("test_signed", "message", {
        maxAge: 1000 * 60, // 60秒
        sameSite: "strict",
        httpOnly: true,
        secure: false, // 在本地測試設置為 false
        signed: true
    });
    return res.status(200).send("Signed Cookie has been set");
});

app.get("/LogCookies", (req, res) => {
    const cookies = req.cookies; // 獲取所有未簽名的 cookies -> 自動轉換成 json 格式
    const signedCookies = req.signedCookies; // 獲取簽名的 cookies -> 自動轉換成 json 格式

    console.log("Raw Cookies:", cookies);
    console.log("Signed Cookies:", signedCookies);

    console.log(`對 raw cookies 直接取值 ${cookies["test"]}`);
    console.log(`對 singed cookies 值接取值 ${signedCookies["test_signed"]}`);

    console.log("END Line ======================================");
    return res.sendStatus(200);
});

app.listen(PORT, () => {
    console.log(`Server listening on   http://localhost:${PORT}`);
    console.log(`Get unsigned cookies: http://localhost:${PORT}/GetCookieUnSigned`);
    console.log(`Get signed cookies:   http://localhost:${PORT}/GetCookieSigned`);
    console.log(`Get all cookies:      http://localhost:${PORT}/LogCookies`);
});
