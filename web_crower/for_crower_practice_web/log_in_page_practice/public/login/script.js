const where = "134.208.49.28";
let form = document.querySelector("form");

form.addEventListener("submit", async function(event) {
    event.preventDefault();

    let password_element = document.querySelector("input[name='password']");
    let username_element = document.querySelector("input[name='username']");

    // 準備要發送的資料
    let data = {
        username: username_element.value,
        password: password_element.value
    };

    password_element.value = '';
    username_element.value = '';

    try {
        let response = await fetch(`http://${where}:5090/api/login`, {
            method: "POST",
            headers: {
                "Content-Type": "application/json"
            },
            body: JSON.stringify(data)
        });

        // 檢查響應的狀態
        if (response.ok) {
            confirm("登入成功！");
            window.location.href = "/protected";
        } else {
            if(response.status == 500){
                return alert("出現錯誤! 伺服器錯誤!");
            }
            // 如果登入失敗
            alert("登入失敗，請檢查用戶名和密碼。");
        }
    } catch (error) {
        console.error("發生錯誤:", error);
        alert("發生錯誤，請稍後再試。");
    }
});
