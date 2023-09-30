<?php
if(isset($_GET['userid'])) {
    // Get user info
    $userId = $_GET['userid'];
    $userInfo = curl_init();
    curl_setopt($userInfo, CURLOPT_URL, "https://dummyapi.io/data/v1/user/$userId");
    curl_setopt($userInfo, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($userInfo, CURLOPT_HTTPHEADER, array(
        "app-id: 6516e4d4eab04b5cc4358a92"
    ));
    $userResponse = curl_exec($userInfo);
    curl_close($userInfo);
    $userData = json_decode($userResponse, true);

    // Get all posts by user
    $userPosts = curl_init();
    curl_setopt($userPosts, CURLOPT_URL, "https://dummyapi.io/data/v1/user/$userId/post");
    curl_setopt($userPosts, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($userPosts, CURLOPT_HTTPHEADER, array(
        "app-id: 6516e4d4eab04b5cc4358a92"
    ));
    $userPostsResponse = curl_exec($userPosts);
    curl_close($userPosts);
    $userPostsData = json_decode($userPostsResponse, true);

} else {
    // Display list of users
    $users = curl_init();
    curl_setopt($users, CURLOPT_URL, "https://dummyapi.io/data/v1/user/");
    curl_setopt($users, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($users, CURLOPT_HTTPHEADER, array(
        "app-id: 6516e4d4eab04b5cc4358a92"
    ));
    $usersResponse = curl_exec($users);
    curl_close($users);

    $usersData = json_decode($usersResponse, true);
    echo "<ul>";
    foreach($usersData['data'] as $user) {
        echo "<li><a href='userinfo.php?id={$user['id']}'>{$user['title']} {$user['firstName']} {$user['lastName']}</a></li>";
    }
    echo "</ul>";
}
?>


<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <link rel="stylesheet" href="css/bootstrap.min.css">
    <title>Document</title>
</head>
<body>
    <section class="d-flex align-items-center justify-content-center h-100 w-100">
        <div class="container d-flex align-items-center justify-content-center h-100 w-100">
            <div class="col-12 col-md-9 col-lg-7 col-xl-6">
                <div class="card">
                    <div class="card-body">
                        <div class="card-body p-4">
                            <img src="<?php echo $userData['picture'] ?>" alt="user" class="img-fluid rounded-circle mb-3 w-25">
                            <?php $userName = $userData['title'] . '. ' .  $userData['firstName'] . ' ' . $userData['lastName']; ?>
                            <h1><?php echo $userName; ?></h1>
                            <p>Email: <?php echo $userData['email'] ?></p>
                            <p>Gender: <?php echo $userData['gender'] ?></p>
                            <p>Phone: <?php echo $userData['phone'] ?></p>
                            <p>Location: <?php echo $userData['location']['street'] . ', ' . $userData['location']['city'] . ', ' . $userData['location']['state'] . ', ' . $userData['location']['country'] ?></p>
                            <p>Registered: <?php echo $userData['registered'] ?></p>
                            <p>Age: <?php echo $userData['dateOfBirth'] ?></p>
                        </div>
                        <hr>
                        <?php foreach($userPostsData['data'] as $post) { ?>
                            <div class="card mb-3">
                                <div class="card-body">
                                    <a href="post.php?postid=<?php echo $post['id']; ?>">
                                        <img src="<?php echo $post['image'] ?>" alt="post" class="img-fluid mb-3">
                                        <h5 class="card-title"><?php echo $post['text'] ?></h5>
                                    </a>
                                    <p class="card-text"><?php echo $post['publishDate'] ?></p>
                                </div>
                            </div>
                        <?php } ?>
                    </div>
                </div>
            </div>
        </div>
    </section>
</body>
</html>
                            
