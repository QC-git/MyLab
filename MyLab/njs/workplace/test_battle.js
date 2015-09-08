


var attributeMap = {
    "1001": {
        "describe": "最大生命",
        "name": "maxLife",
        "type": "num",
        "min" : 1
    },

    "1002": {
        "describe": "当前生命",
        "name": "life",
        "type": "num",
        "max" : "maxLife",
        "min" : 0
    },

    "1003": {
        "describe": "护甲",
        "name": "armor",
        "type": "num"
    },

    "1011": {
        "describe": "位置X",
        "name": "posX",
        "type": "num"
    },

    "1012": {
        "describe": "位置Y",
        "name": "posY",
        "type": "num"
    }

};

var paramsMap = {
    "2001": {
        "describe": "增加最大生命",
        "name": "addMaxLife",

        "mod": "attribute",
        "id": "1001",
        "opt": "add",
        "dir": "it"
    },

    "2002": {
        "describe": "增加生命",
        "name": "addLife",

        "mod": "attribute",
        "id": "1002",
        "opt": "add",
        "dir": "it"
    },

    "2003": {
        "describe": "减少生命",
        "name": "decLife",

        "mod": "attribute",
        "id": "1002",
        "opt": "dec",
        "dir": "it"
    },

    "2011": {
        "describe": "增加状态",
        "name": "addStatus",

        "mod": "status",
        "id": "0",
        "opt": "add",
        "dir": "me"
    },

    "2012": {
        "describe": "删除状态",
        "name": "decStatus",

        "mod": "status",
        "id": "0",
        "opt": "dec",
        "dir": "me"
    },

    "2013": {
        "describe": "删除所有状态",
        "name": "removeStatus",

        "mod": "status",
        "id": "0",
        "opt": "removeAll",
        "dir": "me"
    },

    "2021": {
        "describe": "增加事件",
        "name": "addEvent",

        "mod": "event",
        "id": "0",
        "opt": "add",
        "dir": "me"
    },

    "2022": {
        "describe": "增加事件",
        "name": "addItEvent",

        "mod": "event",
        "id": "0",
        "opt": "add",
        "dir": "it"
    },

    "2031": {
        "describe": "将目标往前推",
        "name": "pushForward"
    }

};

var statusMap = {
    "5001": {
        "describe": "吟唱状态",
        "delay": 999000
    },

    "5002": {
        "describe": "无敌状态",
        "delay": 999000
    },

    "5003": {
        "describe": "晕眩状态",
        "delay": 999000
    },

    "5004": {
        "describe": "减速状态",
        "delay": 999000
    },

    "5005": {
        "describe": "隐身状态",
        "delay": 999000
    }

};

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
            "addEvent": 7001
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
            "addItEvent": 7003
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


