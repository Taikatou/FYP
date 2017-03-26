handlers.UpdateLevelScore = function (args)
{
    //args.  is JSON data we are passing to function from blueprints (Statistics JSON variable)
    var score = args.hiscore; // "hiscore" is the JSON number field named "hiscore" in example above
    var levelname = args.level;   // "level" is the JSON string field named "level"
 
    var keyString = levelname;   
    var dataToUpdate = {};    //this is creating empty JSON data object
    dataToUpdate[keyString] = score;    // make sure we are updating levelname string by a number of score
 
    server.UpdateUserStatistics({   // this is server function which will update user statistic using dataToUpdate
        PlayFabId: currentPlayerId,   // currentPlayerID will be there automatically if player is logged
        UserStatistics: dataToUpdate   // this is actual JSON data that we will be updating. (&lt;"levelname", "score"&gt;)
    });
 
    var message =  "levelname: " + levelname + " score: " + score; 
    return { messageValue: message };
 
}