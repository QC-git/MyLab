


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
        "opt": "add"
    },

    "2002": {
        "describe": "增加生命",
        "name": "addLife",

        "mod": "attribute",
        "id": "1002",
        "opt": "add"
    },

    "2003": {
        "describe": "减少生命",
        "name": "decLife",

        "mod": "attribute",
        "id": "1002",
        "opt": "dec"
    },

    "2011": {
        "describe": "增加状态",
        "name": "addStatus",

        "mod": "status",
        "id": "0",
        "opt": "add"
    },

    "2012": {
        "describe": "删除状态",
        "name": "decStatus",

        "mod": "status",
        "id": "0",
        "opt": "dec"
    }

};

var processMap = {

    "3011": {
        "describe": "增加 静止状态",
        "addStatus": 5001
    },

    "3021": {
        "describe": "增加 静止状态，无敌状态",
        "module": "process",
        "step": [
            {
                "process": 11,
                "value": 1
            },
            {
                "process": 11,
                "value": 2
            }
        ]
    },

    "3031": {
        "describe": "施放技能",
        "module": "process",
        "process": 11,
        "value": 11
    }

};

var statusMap = {
    "5001": {
        "describe": "静止状态",
        "step": [
            {
                "delay": 999000
            }
        ]
    },

    "5002": {
        "describe": "无敌状态",
        "step": [
            {
                "delay": 999000
            }
        ]
    },

    "3": {
        "describe": "晕眩状态",
        "step": [
            {
                "delay": 999000
            }
        ]
    },

    "11": {
        "describe": "施放技能状态",
        "step": [
            {
                "process": 11,
                "value": 1,
                "delay": 1000
            },
            {
                "process": 3,
                "value": 100
            }
        ]
    },

    "12": {
        "describe": "读条施放技能状态",
        "step": [
            {
                "count": 5,
                "check": {
                    "noStatus": 3,
                    "opt": "quit"
                },
                "event": {
                    "on": 1,
                    "opt": "process",
                    "process": 3
                },
                "process": 11,
                "value": 1,
                "delay": 100
            },
            {
                "process": 3,
                "value": 100
            }
        ]
    }

};




function Unit() {
    this.attrMap = {};

}



var obj = new WorldObject();



