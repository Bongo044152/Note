import express from 'express';
import { UpdateLog, SendFile } from './tools.mjs';
import jwt from 'jsonwebtoken';
import cookieParser from 'cookie-parser';
import path from 'path';
import { fileURLToPath } from 'url';

const where = "134.208.49.28";

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);
const secret = "4x33515150 669191 4117374";

const app = express();
app.use(express.json());
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public', "login")));
app.use(express.static(path.join(__dirname, 'public', "protect")));

const authenticateUser = (username, password) => {
    return username === "明哲" && password === "666";
};

const Accessed = (req, res, next) => {
    const mes = `${req.ip} 嘗試登入`;
    UpdateLog(mes, "accessLog");
    next();
}

const PORT = 5090;

app.get('/', (req, res) => {
    const filePath = path.join(__dirname, "public", "login", "index.html");
    return SendFile(filePath, req, res);
});

app.post("/api/login", Accessed, (req, res, next) => {
    const { password, username } = req.body;
    if (!password || !username) return res.sendStatus(400);

    if (!authenticateUser(username, password)) {
        return res.sendStatus(401);
    }

    next();
}, (req, res) => {
    const { username } = req.body;
    const token = jwt.sign({ username }, secret, { expiresIn: '5m' });
    res.cookie('token', token, {
        httpOnly: true,
        maxAge: 1000 * 60 * 5
    });
    return res.sendStatus(200);
});

app.get("/protected" , (req, res) => {
    const token = req.cookies.token;
    if (token) {
        jwt.verify(token, secret, (err, decoded) => {
            if (err) return res.sendStatus(403);
            const filePath = path.join(__dirname, "public", "protect", "index.html");
            return SendFile(filePath, req, res);
        });
    } else {
        return res.sendStatus(401);
    }
})

// 啟動伺服器
app.listen(PORT, () => {
    console.log(`Server is running on http://${where}:${PORT}`);
});