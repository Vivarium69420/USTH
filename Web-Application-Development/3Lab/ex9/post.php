<?php
    isset($_GET['postid']) ? $postId = $_GET['postid'] : $postId = null;
    // Get post info
    $postId = $_GET['postid'];
    $postInfo = curl_init();
    curl_setopt($postInfo, CURLOPT_URL, "https://dummyapi.io/data/v1/post/$postId");
    curl_setopt($postInfo, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($postInfo, CURLOPT_HTTPHEADER, array(
        "app-id: 6516e4d4eab04b5cc4358a92"
    ));
    $postResponse = curl_exec($postInfo);
    curl_close($postInfo);
    $postData = json_decode($postResponse, true);

    // Get owner info
    $ownerId = $postData['owner']['id'];
    $ownerInfo = curl_init();
    curl_setopt($ownerInfo, CURLOPT_URL, "https://dummyapi.io/data/v1/user/$ownerId");
    curl_setopt($ownerInfo, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($ownerInfo, CURLOPT_HTTPHEADER, array(
        "app-id: 6516e4d4eab04b5cc4358a92"
    ));
    $ownerResponse = curl_exec($ownerInfo);
    curl_close($ownerInfo);
    $ownerData = json_decode($ownerResponse, true);

    // Get comments
    $comments = curl_init();
    curl_setopt($comments, CURLOPT_URL, "https://dummyapi.io/data/v1/post/$postId/comment");
    curl_setopt($comments, CURLOPT_RETURNTRANSFER, true);
    curl_setopt($comments, CURLOPT_HTTPHEADER, array(
        "app-id: 6516e4d4eab04b5cc4358a92"
    ));
    $commentsResponse = curl_exec($comments);
    curl_close($comments);
    $commentsData = json_decode($commentsResponse, true);
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
                        <h1><?php echo $postData['text'] ?></h1>
                        <img src="<?php echo $postData['image'] ?>" alt="post" class="img-fluid mb-3">
                        <p>Owner: <a href="userinfo.php?userid=<?php echo $ownerData['id'] ?>"><?php echo $ownerData['firstName'] . ' ' . $ownerData['lastName'] ?></a></p>
                        <p>Published: <?php echo $postData['publishDate'] ?></p>
                        <p>Link: <a href="<?php echo $postData['link'] ?>"><?php echo $postData['link'] ?></a></p>
                        <p>Tags: <?php echo implode(', ', $postData['tags']) ?></p>
                        <p>Likes: <?php echo $postData['likes'] ?></p>
                    </div>
                    <hr>
                    <div class="card-body">
                    <?php foreach ($commentsData['data'] as $comment) { ?>
                        <div class="card mb-3">
                            <div class="card-body">
                            <p>By: <a href="userinfo.php?userid=<?php echo $comment['owner']['id'] ?>"><?php echo $comment['owner']['firstName'] . ' ' . $comment['owner']['lastName'] ?></a></p>
                                <p><?php echo $comment['message'] ?></p>
                                <p>Published: <?php echo $comment['publishDate'] ?></p>
                                <p>Likes: <?php echo $comment['likes'] ?></p>
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
