import file_manager from './file_manager.mjs';
const my_file_manager = new file_manager();

const filePath1 = "./data/test.txt";
my_file_manager.writeFile(filePath1, "Hello fs!");
const filePath2 = "./data/test.json";
const my_obj = [
    {
        username: "明哲",
        age: "56"
    }
]

const data = JSON.stringify(my_obj, null, 2);
my_file_manager.writeFile(filePath2, data);

const res = await my_file_manager.readFile(filePath1);

console.log(res);