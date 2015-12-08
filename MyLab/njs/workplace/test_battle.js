

var eventMap = {
    "7001": {
        "describe": "监听晕眩状态",

        "mod": "status",
        "status": "5003",
        "opt": "add"
    },

    "7002": {
        "describe": "监听靠近墙"
    },

    "7003": {
        "describe": "监听死亡",

        "mod": "attribute",
        "id": "1002",
        "opt": "dec",
        "value": 0
    }
};

var logicMap = {
    "6001" : {  //读条施法
        "1": {
            "addStatus": 5001,
            "addEvent": 7001,
            "delay": 1000
        },
        "2": {
            "waitLogic": 1,
            "waitEvent": 0,

            "decLife": 100
        },
        "99": {
            "waitEvent": 7001,

            "decStatus": 5011,
            "fail": 1
        }
    },
    "6002": { //将目标往前推10距离， 并造成减速和伤害， 如果撞墙则造成晕眩
        "1": {
            "pushForward": 10,
            "addEvent": 7002
        },
        "2": {
            "waitLogic": 1,

            "addStatus": 5004,
            "decLife": 100
        },
        "3": {
            "waitEvent": 7002,

            "addStatus": 5003,
            "decLife": 100
        }
    },
    "6003": { //装进目标身体， 并操控对方, 时间到或对方死亡则脱离
        "1": {
            "addStatus": 5005,
            "control": 1, //todo 控制对方
            "addItEvent": 7003,
            "delay": 5000
        },
        "2": {
            "waitLogic": 1,
            "decStatus": 5005
        },
        "3": {
            "waitEvent": 7003,
            "decStatus": 5005
        }
    }
};


