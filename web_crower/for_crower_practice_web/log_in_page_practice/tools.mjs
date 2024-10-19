import fs from 'fs/promises'; // 使用 fs/promises 來支持 async/await
import path from 'path';
import { fileURLToPath } from 'url';

const __filename = fileURLToPath(import.meta.url);
const __dirname = path.dirname(__filename);

const getCurrentTime = () => {
    const now = new Date();
    const year = now.getFullYear();
    const month = String(now.getMonth() + 1).padStart(2, '0');
    const day = String(now.getDate()).padStart(2, '0');
    const hours = String(now.getHours()).padStart(2, '0');
    const minutes = String(now.getMinutes()).padStart(2, '0');

    return `${year}-${month}-${day} ${hours}:${minutes}`;
};

const UpdateLog = async (mes, fileName) => {
    const time = getCurrentTime();

    if (!mes || !fileName) {
        throw new Error("Missing some args.");
    } else if (!(fileName.includes("accessLog") || fileName.includes("errorLog"))) {
        throw new Error("fileName is illegal");
    }

    const filePath = path.join(__dirname, "log", `${fileName}.json`);

    try {
        // 讀取檔案
        let data = await fs.readFile(filePath, 'utf8').catch(() => '[]'); // 如果檔案不存在，返回空的 JSON 陣列
        
        // 檢查是否為有效 JSON
        if (!data || data.trim() === '') {
            data = '[]'; // 如果為空，設置為空陣列
        }

        const jsonData = JSON.parse(data);

        jsonData.push({
            time: time,
            mes: mes,
        });

        const newData = JSON.stringify(jsonData, null, 2); // 格式化 JSON

        // 寫入新內容
        await fs.writeFile(filePath, newData);
        return true;
    } catch (err) {
        console.error('Error updating access log:', err);
        throw err; // 將錯誤重新拋出
    }
};

const SendFile = (filePath, req, res) => {
    return res.sendFile(filePath, async err => {
        if (err) {
            console.error(err);

            try{
                await UpdateLog("Send file error", "errorLog");
            }
            catch (err){
                console.log("讀寫檔案發生錯誤， error catched in index.mjs in line 20");
                console.error(err);
            }

            return res.status(500).json({
                status: "ERROR",
                statusCode: 500,
                errorMessage: "Something went wrong on the server"
            });
        }
    });
} 

export { UpdateLog, SendFile };