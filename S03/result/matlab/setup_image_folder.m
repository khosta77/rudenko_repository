function setup_image_folder()
    [~, lastFolder, ~] = fileparts(pwd);
    if (~isfolder('img') && (lastFolder ~= "img"))
        mkdir('img');
        cd('img');
    elseif (lastFolder ~= "img")
        cd('img');
    end
end

