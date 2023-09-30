<?php
$users = curl_init();
curl_setopt($users, CURLOPT_URL, "https://dummyapi.io/data/v1/user/");
curl_setopt($users, CURLOPT_RETURNTRANSFER, true);
curl_setopt($users, CURLOPT_HTTPHEADER, array(
    "app-id: 6516e4d4eab04b5cc4358a92"
));
$usersResponse = curl_exec($users);
curl_close($users);

$usersData = json_decode($usersResponse, true);
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
                    <div class="card-body d-flex align-items-center justify-content-around">
                        <a href="userinfo.php">Users</a>
                        <a href="listpost.php">Posts</a>
                    </div>
                </div>
                <div class="card">
                    <div class="card-body">
                    <?php foreach ($usersData['data'] as $user) { ?>
                            <div class="card-body p-4">
                            <a href="userinfo.php?userid=<?php echo $user['id'] ?>">
                                <img src="<?php echo $user['picture'] ?>" alt="user" class="img-fluid rounded-circle mb-3 w-25">
                                <?php $userName = $user['title'] . '. ' .  $user['firstName'] . ' ' . $user['lastName']; ?>
                                <h1><?php echo $userName; ?></h1>
                            </a>
                            </div>
                        <?php } ?>
                    </div>
                </div>
            </div>
        </div>
    </section>
</body>
</html>
