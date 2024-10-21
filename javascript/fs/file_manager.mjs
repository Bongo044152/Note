import fs from 'fs/promises';

export default class FileManager {
    async writeFile(filePath, data) {
        if (!filePath || !data)
            throw new Error("Parameters 'filePath' and 'data' are required!");

        try {
            await fs.writeFile(filePath, data);
        } catch (err) {
            throw new Error(`Failed to write file: ${err}`);
        }
    }
    async readFile(filePath) {
        if(! filePath)
            throw new Error(`the parameter 'filePath' is required!`);

        try{
            return await fs.readFile(filePath, 'utf-8'); // 指定編碼
        }
        catch (err){
            console.error(`error caused while try to readfile: ${err}`);
            throw err;
        }
    }
}